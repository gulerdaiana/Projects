using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using LabCSharp.domain;
using LabCSharp.validators;

namespace LabCSharp.repository.MemoryRepo
{
    public class InMemoryRepository<ID,E>:Repository<ID,E> where E:Entity<ID>
    {
        protected IDictionary<ID, E> Entities = new Dictionary<ID, E>();
        protected Validators<E> Validator;

        public InMemoryRepository(Validators<E> validator)
        {
            Validator = validator;
        }

        public E save(E entity)
        {
            Validator.validate(entity);
            if (Entities.ContainsKey(entity.id))
            {
                return entity;
            }
            Entities.Add(entity.id,entity);
            return entity;
        }

        public E delete(ID id)
        {
            throw new System.NotImplementedException();
        }

        public E findOne(ID id)
        {
            if(id == null)
                throw new Exception("Id must not be null");
            if (!Entities.ContainsKey(id))
            {
                throw new Exception("Id dosen't exist");
            }
            return Entities[id];
        }

        public IEnumerable<E> findAll()
        {
            return Entities.Values.ToList<E>();
        }
    }
}